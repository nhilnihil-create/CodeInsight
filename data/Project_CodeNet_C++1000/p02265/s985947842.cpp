#include <iostream>
#include <string>

using namespace std;


class Linked_list{
  struct Item{
    int num;
    Item* next;
    Item* prev;
  };
  Item *first,*last;

  public:
  Linked_list(){
    first = NULL;
    last = NULL;
  }

  void insert(int x){
    Item* item = new Item();
    item->num = x;
    item->prev = NULL;
    item->next = first;
    if(item->next!=NULL) item->next->prev = item;
    first = item;
    if(last == NULL) last = item;
  }

  void delete_item(int x){
    Item* item = first;
    while(item != NULL){
      if(item->num == x){
        if(item->prev!=NULL){ item->prev->next = item->next;
         } else { first = item->next; }
        if(item->next!=NULL){ item->next->prev = item->prev;
        } else { last = item->prev; }
        delete item;

        return;
      }
      item = item->next;
    }
  }

  void delete_first(){
    Item *item = first;
    if(first->next == NULL) last = NULL;
    first = item->next;
    delete item;
    if(first!=NULL)first->prev = NULL;
  }

  void delete_last(){
    Item *item = last;
    if(last->prev == NULL) first = NULL;
    last = item->prev;
    if(last!=NULL) last->next = NULL;
    delete item;
  }

  int pop_first(){
    Item *item = first;
    first = item->next;
    return item->num;
  }

  bool is_empty(){
    return first == NULL;
  }
};

int main(){
  ios::sync_with_stdio(false);
  Linked_list list;
  int n;
  string ope;
  cin>>n;
  for(int i=0;i<n;i++){ 
    cin>>ope;
    if(ope=="insert"){
      int x;
      cin>>x;
      list.insert(x);
    }else if(ope=="delete"){
      int x;
      cin>>x;
      list.delete_item(x);
    }else if(ope=="deleteFirst"){
      list.delete_first();
    }else if(ope=="deleteLast"){
      list.delete_last();
    }
  }

  int count = 0;
  while(!list.is_empty()){
    if(count)cout<<" ";
    cout<<list.pop_first();
    count++;
  }
  cout<<endl;
}