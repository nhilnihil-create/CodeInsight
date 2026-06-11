#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,c;
    string s;
    cin>>n>>k>>c;
    cin>>s;
    vector<int>A;
    vector<int>B;
    for (int i = 0;i<n;i++){
        if (s[i]=='o'){
            A.push_back(i);
            i+=c;
        }
    }
    for (int i = n-1;i>=0;i--){
        if (s[i]=='o'){
            B.push_back(i);
            i-=c;
        }
    }
    for (int i = 0;i<k;i++){
        if (A[i]==B[k-i-1]){
            cout<<A[i]+1<<endl;
        }
    }
    return 0;
}