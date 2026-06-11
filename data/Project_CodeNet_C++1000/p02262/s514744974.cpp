//ALDS1_2D
#include <iostream>
#include <vector>

using namespace std;

int insertionSort(vector<int>& data,int g){
 int cnt=0;
 const int n=data.size();
 for(int i=g;i<n;i++){
  int v=data.at(i);
  int j=i-g;
  while(j>=0 && data.at(j)>v){
   data.at(j+g)=data.at(j);
   j=j-g;
   cnt++;
  }
  data.at(j+g)=v;
 }
 return cnt;
}

void shellSort(vector<int>& data){
 const int n=data.size();
 vector<int> G;
 G.push_back(1);
 for(int i=0;n>3*G.at(i)+1;i++){
  G.push_back(3*G.at(i)+1);
 }

 int cnt=0;
 int m=G.size();
 for(int i=m-1;i>=0;i--){
  cnt+=insertionSort(data,G.at(i));
 }

 cout<<m<<endl;
 for(int i=m-1;i>=0;i--){
  cout<<G.at(i);
  if(i!=0) cout<<" ";
  else cout<<endl;
 }
 cout<<cnt<<endl;
}

int main(){
 int n;
 cin>>n;

 vector<int> data(n,0);
 for(int i=0;i<n;i++){
  cin>>data.at(i);
 }

 shellSort(data);
 for(int i=0;i<n;i++) cout<<data.at(i)<<endl;
 
 return 0;
}