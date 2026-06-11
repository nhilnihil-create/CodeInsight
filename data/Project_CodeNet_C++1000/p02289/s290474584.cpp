#include<iostream>
#include<cstdio>
#define MAX 2000200
#define INT_MIN -2000000300
using namespace std;
typedef long long ll;
 
class priority_queue{
private:
  int index;
  int Array[MAX];
 
  int heapIncreaseKey(int i,ll key){
    if(key < Array[i])return -1;
    Array[i] = key;
    while(i > 1 && Array[getParent(i)] < Array[i]){
      ll h = Array[i];
      Array[i] = Array[getParent(i)];
      Array[getParent(i)] = h;
      i = getParent(i);
    }
  }
 
  void maxHeapify(int i){
    ll l = getLeft(i);
    ll r = getRight(i);
    ll largest;
    if(l <= index && Array[l] > Array[i])largest=l;
    else largest=i;
    if(r<=index && Array[r] > Array[largest])largest = r;
    if(largest != i){
      ll h;
      h = Array[i];
      Array[i] = Array[largest];
      Array[largest] = h;
      maxHeapify(largest);
    } 
  }
 
public:
 
  priority_queue(){
    index = 0;
  }
 
  void Insert(ll key){ //maxHeapInsert
    ++index;
    Array[index] = INT_MIN;
    heapIncreaseKey(index,key);
  }
 
  ll heapExtractMax(){
    if(index < 1)return -1;
    ll max = Array[1];
    Array[1] = Array[index];
    index--;
    maxHeapify(1);
    return max;
  }
 
 
  int getParent(int i){
    return i/2;
  }
 
  int getLeft(int i){
    return 2*i;
  }
 
  int getRight(int i){
    return 2*i+1;
  }
 
};
 
 
 
int main(){
  string op;
  ll val;
  priority_queue pque = priority_queue();
 
  while(true){
    cin >> op;
    if(op == "insert"){
      scanf("%lld",&val);
      pque.Insert(val);
    }
    else if(op == "extract"){
      printf("%lld\n",pque.heapExtractMax());
    }
    else if(op == "end")break;
  }
 
  return 0;
}