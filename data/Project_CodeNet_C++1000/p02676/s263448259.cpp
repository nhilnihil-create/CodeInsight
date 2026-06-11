// i am a noob

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

#define endl "\n"

const int MOD = 1000000007;


int main()
{
    int a,len;
    str x;
    cin >> a >> x;
    len = x.length();
    if (len <= a){
        cout << x << endl;
    }
    else {
        for(int i = 0;i < a ; i++){
            cout << x[i] ;
            }
            cout <<  "...";
                    }


	return 0;
}
