#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define sec second

ll n,m,k,x,x2,y,y2,sol=0,rep,cnt,sad;
ll R,G,B;
char c;
string s;
vector <ll> V;

int main()
{
    cin >> n;
    cin >> s;
    for (int i=0;i<n;i++){
        c=s[i];
        R=0;
        G=0;
        B=0;
        for (int j=0;j<i;j++){
            if (s[j]=='R') R++;
            if (s[j]=='G') G++;
            if (s[j]=='B') B++;

            if (s[j]!=c){
                if ('R'!=c && 'R'!=s[j]){
                    x=R;
                    if (j-(i-j)>=0 && s[j-(i-j)]=='R') x--;
                    sol+=x;
                }
                if ('G'!=c && 'G'!=s[j]){
                    x=G;
                    if (j-(i-j)>=0 && s[j-(i-j)]=='G') x--;
                    sol+=x;
//                    if (j-(i-j)>=0 && s[i-j]=='G') cout << "noooo ";
//                    cout << x << " " << G << " " << i-j << "\n";
                }
                if ('B'!=c && 'B'!=s[j]){
                    x=B;
                    if (j-(i-j)>=0 && s[j-(i-j)]=='B') x--;
                    sol+=x;
                }
            }
        }
    }
    cout << sol;
}
