#include<bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define sci(x) int x; scanf("%d", &x);
#define TC(x) sci(x); while(x--)
typedef long long ll;
using namespace std;

bool pelindrome(string s)
{
    int len=s.length();
    string s1=s;
    reverse(all(s1));
    if(s==s1) return true;
    else return false;
}

string strmaker(string s, int a, int b)
{
    string s1;
    for(int i=a-1;i<=b-1;i++){
        s1.pb(s[i]);
    }
    return s1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s,s1,s2;
    cin>>s;
    int n=s.length();
    s1=strmaker(s, 1, (n-1)/2);
    s2=strmaker(s, (n+3)/2, n);
    if(pelindrome(s) && pelindrome(s1) && pelindrome(s2)) cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
