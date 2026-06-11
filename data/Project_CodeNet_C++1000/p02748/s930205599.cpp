#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int func(int x)
{
    if(x%2==0)
    {
        return x/2;
    }
    else
    {
        return 3*x+1;
    }
}
int main()
{
    int a,b,m;
    cin>>a>>b>>m;
    vector <int> A(a);      //冷蔵庫
    vector <int> B(b);      //電子レンジ    
    vector <int> C(m);      //クーポン

    rep(i,a) cin>>A[i];
    rep(i,b) cin>>B[i];

    int minElementA = *min_element(A.begin(), A.end());  //冷蔵後の最小値
    int minElementB = *min_element(B.begin(), B.end());  //電子レンジの最小値   
    int minV = minElementA+minElementB;

    //クーポン適用
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        cin>>C[i];
        if(A[x-1]+B[y-1]-C[i]<minV)
        {
            minV=A[x-1]+B[y-1]-C[i];
        }
    }

    cout<<minV<<endl;


    return 0;
}