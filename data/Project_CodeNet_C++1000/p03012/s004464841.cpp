#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
    int N,R=0,R1=0,ans=1000000;
    cin>>N;
    vector<int>W(N);
    for(int i=0;i<N;i++){
        cin>>W[i];
        R+=W[i];
    }
    reverse(W.begin(),W.end());
    for(int i=0;i<N;i++){
        R1+=W[i];
        R-=W[i];
        ans=min(ans,abs(R1-R));
    }
    cout<<ans<<endl;


}