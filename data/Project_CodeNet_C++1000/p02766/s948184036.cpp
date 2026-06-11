#include <bits/stdc++.h>
using namespace std;
int main(){
int N,K;
cin>>N>>K;
int answer=0;
while(N)
{
N=N/K;
answer++;
}
cout<<answer<<endl;
}
