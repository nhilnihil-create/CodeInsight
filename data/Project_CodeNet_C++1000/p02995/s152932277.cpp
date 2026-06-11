#include<bits/stdc++.h>
using namespace std;
#define For(start,end) for(int i = (int)start;i<(int)end;i++)
using Int = long long int;
using TDim = vector<vector<int>>;
//xとyの最小公倍数=>素因数分解
Int euclid(Int b,Int a){

    if(b%a==0)return a;
    return euclid(a,b%a);
}
Int start_E(Int b,Int a)
{
    Int big=max(b,a);
    Int small=min(b,a);
    return euclid(big,small);
}
int main()
{
    Int A,B,C,D;
    cin>>A>>B>>C>>D;
    if(A==B)
    {
        if(A%C==0||A%D==0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
        
    }
  
    else
    {
    Int n = B-A+1;//n個
    Int Ca= A/C;
    Int Da= A/D;
    Int Cb= B/C;
    Int Db= B/D;
    Int gcm=start_E(C,D);
    Int CDa = A/(gcm*(C/gcm)*(D/gcm));
    Int CDb = B/(gcm*(C/gcm)*(D/gcm));
    Int youC=(A%C==0)?1:0;
    Int youD=(A%D==0)?1:0;
    Int youCD=(A%(gcm*(C/gcm)*(D/gcm))==0)?1:0;
    cout<<n-(Db-Da)-(Cb-Ca)-youC-youD+youCD+(CDb-CDa)<<endl;
    }    
}
