#include <iostream>
#include <algorithm>
using namespace std;
long N,K;
long long cnt;
int H[201010];
bool compare(int a,int b)
{
  return a>b;
}

int main(){
    cin>>N>>K;
    for(int i = 0;i<N;i++){
        cin>>H[i];
        cnt+=H[i];
    }
    sort(H,H+N,compare);
    for(int i=0;i<K;i++){
        cnt-=H[i];
    }
    cout<<cnt;
}