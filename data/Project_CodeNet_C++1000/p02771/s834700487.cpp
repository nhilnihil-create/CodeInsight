#include <bits/stdc++.h>
using namespace std;
#define loop(i,n) for (int i =0;i<(n);i++)
typedef long long ll;
   

int main (){
        ios_base::sync_with_stdio(0); cin.tie(0);
        //freopen("a.txt", "r", stdin);

        int a,b,c;

        cin>>a>>b>>c;
      //  cout <<a<<b<<c;
        string ans = "No";
        if (a==b && a != c) ans = "Yes";
        if (a==c && a != b) ans = "Yes";
        if (c==b && a != c) ans =  "Yes";

        cout <<ans<< endl;
        return 0;

    }


