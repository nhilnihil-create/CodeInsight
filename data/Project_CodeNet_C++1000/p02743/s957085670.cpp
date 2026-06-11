#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    long double A,B,C;
    cin >> A >> B >> C;
    long double eps=1.0E-14;
    if(sqrt(A)+sqrt(B)+eps<sqrt(C)){
        cout<<"Yes"<<endl;
    }else {
        cout<<"No"<<endl;
    }
    return 0;
}