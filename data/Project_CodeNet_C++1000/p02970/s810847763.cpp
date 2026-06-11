#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int  main(){
int N,D;
cin>>N>>D;
int answer=0;
answer+=N/(D*2+1);
if(N%(D*2+1)!=0){
    answer++;
}
cout<<answer<<endl;
}
