#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N  =200005;

int n, a[11][11];
ll ans;
int power (int x){
int v=1;
for ( int i=0; i<x; i++) v*=10;
return v;
}


int solve (string x){
int no =0, f=0, last;
for (int i= x.size()-1; i >=0; i--){
    no += (x[i]-48)* power(f);
    if (f) f++;
    if (x[i]-48 >0 && f==0) f++, last =x[i]-48;
}
if (no > n) return 0;
return last;
}

int main()
{
        cin >> n;

        for (int i=1; i<=9; i++){
        for (int j=0; j<=9; j++){
         for (int k=0; k<=9; k++){
         for (int l=0; l<=9; l++){
         for (int m=0; m<=9; m++){
         for (int r=0; r<=9; r++){
        char c; string x;
        c=i+48, x+= c, c= j+48, x+=c,c= k+48, x+=c,c= l+48, x+=c,c= m+48, x+=c,c= r+48, x+=c;
        int  h = solve(x);
        if (h)  a[i][h]++;

         }
        }
        }
        }
        }
        }

         for (int i=1; i<=9; i++){
        for (int j=0; j<=9; j++){
         for (int k=0; k<=9; k++){
         for (int l=0; l<=9; l++){
         for (int m=0; m<=9; m++){
         for (int r=0; r<=9; r++){
        char c; string x;
        c=i+48, x+= c, c= j+48, x+=c,c= k+48, x+=c,c= l+48, x+=c,c= m+48, x+=c,c= r+48, x+=c;
        int  h = solve(x);
        if (h)  ans +=a[h][i];
        }
        }
        }
        }
        }
        }

        cout << ans;
    return 0;
}
