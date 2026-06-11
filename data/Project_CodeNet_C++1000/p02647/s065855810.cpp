#include <iostream>
#include <cstdio>
#include <algorithm>
#define ALL(x) (x).begin(),(x).end()
using namespace std;
const int MAXN = 200005;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for (int i = 0; i < (int)v.size(); ++i) os << v[i] << " ";
    return os;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int>A(n);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int flag = 1;
    while(k--&&flag){
        flag = 0 ;
        vector<int>B(n);
        for(int i=0;i<n;i++){
            int l = max(0,i-A[i]);
            int r = min(i+A[i],n-1);
            B[l]++;
            if(r+1<n)
                B[r+1]--;
        }
        for(int i=0;i<n-1;i++){
            B[i+1]+=B[i];
            if(B[i+1]!=n)
                flag=1;
        //    cout << B[i] <<" \n"[i=n-1];
        }
        if(B[0]!=n)
            flag = 1;
        A=B;
    }
    cout <<A<<endl;
    return 0;
}
