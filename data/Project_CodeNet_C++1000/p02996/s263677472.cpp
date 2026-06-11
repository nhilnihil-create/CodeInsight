#include <bits/stdc++.h>
using namespace std ;
 
int main(){
    int N;cin>>N;
    vector<pair<int,int>> A;
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        A.emplace_back(b,a);
    }
    sort(A.begin(),A.end());

 
    int judge=0,sum=0;
    for(int i=0;i<N;i++){
        sum+=A[i].second;
        if(A[i].first>=sum) judge+=1;
    }
    if(judge==N) cout << "Yes" <<endl;
    else cout << "No" << endl;
}