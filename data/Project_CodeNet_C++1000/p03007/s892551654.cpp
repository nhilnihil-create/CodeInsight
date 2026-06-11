#include <bits/stdc++.h>
#define rep(i,N) for(int i=0;i<N;i++)
using namespace std;
long long  INF=1000000000000000000;
long long mod=1000000007;
using namespace std;


int main(){
int N;
cin>>N;
vector<long long >A(N);
rep(i,N){
    cin>>A[i];
}
sort(A.begin(),A.end());
bool both=false;
if(A[0]<0 && A[N-1]>=0)both=true;

vector<pair<long long,long long>>ope(N-1);
if(both){
    for(int i=1;i<N-1;i++){
        if(A[i]<0)
        {
            ope[i-1]=make_pair(A[N-1],A[i]);
            A[N-1]-=A[i];
        }
        else{
            ope[i-1]=make_pair(A[0],A[i]);
            A[0]-=A[i];
        }
    }
    ope[N-2]=make_pair(A[N-1],A[0]);
    A[N-1]-=A[0];
    cout<<A[N-1]<<endl;
}
else if(A[N-1]<0){
    for(int i=N-2;i>=0;i--){
            ope[N-2-i]=make_pair(A[N-1],A[i]);
            A[N-1]-=A[i];    
    }
    cout<<A[N-1]<<endl;
}
else if(A[0]>=0){
    for(int i=1;i<N-1;i++){
            ope[i-1]=make_pair(A[0],A[i]);
            A[0]-=A[i];    
    }
    ope[N-2]=make_pair(A[N-1],A[0]);
    A[N-1]-=A[0];
    cout<<A[N-1]<<endl;
}

rep(i,N-1){
    cout<<ope[i].first<<" "<<ope[i].second<<endl;
}
 return 0;
}
/*
bymyself

second 11m50s
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