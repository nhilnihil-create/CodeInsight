#include<iostream>
int main(){
 int N;
 std::cin>>N;
 long long answer=0;
 int u,v;
 for(int i=0;i<N-1;i++){
  answer+=((long long)(i+1))*(N-i);
  std::cin>>u>>v;
  if(u>v){
	  answer-=((long long)v)*(N-u+1);
  }else{
	  answer-=((long long)u)*(N-v+1);
  }
 }
 answer+=N;
 std::cout<<answer;
 return 0;
}
