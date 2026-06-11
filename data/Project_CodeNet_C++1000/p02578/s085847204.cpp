#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <long long> A;
    long long a,b;
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b;
        A.push_back(b);
    }
    long long cnt=0;
    for(int i=0;i<A.size()-1;i++){
        if(A[i]>A[i+1]){
            cnt+=A[i]-A[i+1];
            A[i+1]=A[i];
        }
    }
    cout<<cnt;
}
