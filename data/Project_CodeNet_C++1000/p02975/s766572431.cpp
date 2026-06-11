#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;cin>>N;
    long array[N];
    for(int i=0;i<N;i++)cin>>array[i];
    long ans=array[0];
    for(int i=1;i<N;i++){
      ans=ans^array[i];
    }
    if(ans==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

}