#include<iostream>
#include<list>
#include<string>
#include<algorithm>
int main()
{
  std::list<int> lst;
  std::string str;
  int n;
  int tmp;
  std::cin>>n;
  for(int i=0;i<n;i++){
    std::cin>>str;
    if(str=="insert"){
      std::cin>>tmp;
      lst.push_front(tmp);
    }else if(str=="deleteFirst"){
      lst.pop_front();
    }else if(str=="deleteLast"){
      lst.pop_back();
    }else{
      std::cin>>tmp;
      std::list<int>::iterator it=find(lst.begin(),lst.end(),tmp);
      if(it!=lst.end()){
	lst.erase(it);
      }
    }
  }

  for(std::list<int>::iterator it=lst.begin();it!=lst.end();++it){
    if(it!=lst.begin()){
      std::cout<<' ';
    }
    std::cout<<*it;
  }
  std::cout<<'\n';
  return 0;
}

