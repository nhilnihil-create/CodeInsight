#include<bits/stdc++.h>
using namespace std;

int main(){
int N;
cin>>N;
string S;
cin>>S;

int a=0;
for(int i=1;i<N;i++){
  if(S[i-1]!=S[i]){
    a++;
  }
}
a+=1;
cout<<a<<endl;

}
