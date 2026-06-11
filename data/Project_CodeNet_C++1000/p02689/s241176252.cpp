#include <bits/stdc++.h>
#include <iostream>
#include <math.h>    //pow(x,y)=x^y 99999とかの場合+1するif文
#include <algorithm> //sort(a.begin(), a.end());reverse(a.begin(), a.end());
#define rep(init, i, n) for (int i = init; i < (n); i++)
#define ll long long
#define rev(s) reverse(s.begin(), s.end())
#define sor(v) sort(v.begin(), v.end())
#define PI 3.14159265358979323846264338327950
//コード自動整形 Shift + Option + F @vscode
using namespace std;

/////main/////
int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N), A(M), B(M), goodlocation(N, 1);
    ll sum = 0;

    rep(0,i,N){
        cin>>H.at(i);
    }

    rep(0, i, M)
    {
        cin >> A.at(i) >> B.at(i);
    }

    rep(0, i, M)
    {
        ll a = A.at(i); a = a-1;
        ll b = B.at(i);b = b-1;;
        if (H.at(a) >= H.at(b))
        {
            goodlocation.at(b) = 0;
        }
        if (H.at(b) >= H.at(a))
        {
            goodlocation.at(a) = 0;
        }
    }
    //rep(0,i,M){
    //    cout<< "A("<< i+1<<")=" << A.at(i)<<"B("<< i+1<<")=" << B.at(i)<<endl;
    //}
    rep(0, i, N)
    {
        sum += goodlocation.at(i);
    }
    cout << sum << endl;
}
/////main/////

/////function/////