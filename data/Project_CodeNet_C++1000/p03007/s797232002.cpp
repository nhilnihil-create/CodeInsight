#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){

int N;
cin>>N;
vector<long long> A(N);
for(int i=0;i<N;i++){
    cin>>A[i];
}
sort(A.begin(),A.end());

bool both=false;
if(A[0]<0 && A[N-1]>=0)both=true;

vector<pair<long long,long long>>ans(N-1);
if(both){
    for(int i=1;i<N-1;i++){
        if(A[i]<0){
            ans[i-1]=make_pair(A[N-1],A[i]);
            A[N-1]-=A[i];
        }
        else if(A[i]>=0){
            ans[i-1]=make_pair(A[0],A[i]);
            A[0]-=A[i];
        }
    }
    ans[N-2]=make_pair(A[N-1],A[0]);
    cout<<A[N-1]-A[0]<<endl;
    for(int i=0;i<N-1;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
else if(A[0]>=0){
    for(int i=1;i<N-1;i++){
        ans[i-1]=make_pair(A[0],A[i]);
        A[0]-=A[i];
    }
    ans[N-2]=make_pair(A[N-1],A[0]);
    cout<<A[N-1]-A[0]<<endl;
    for(int i=0;i<N-1;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}
else if(A[0]<0){
    for(int i=N-2;i>=0;i--){
        ans[N-2-i]=make_pair(A[N-1],A[i]);
        A[N-1]-=A[i];
    }
    cout<<A[N-1]<<endl;
    for(int i=0;i<N-1;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}

 return 0;
}
/*
3
1 -1 2


4
-1 1
2 -2


3
1 1 1

1
1 1
1 0
*/