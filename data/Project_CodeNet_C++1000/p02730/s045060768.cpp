#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
// scanf("%d %d %d %d", &w, &b, &d, &s); %lld
// printf("%d\n", points);
// const double PI = acos(-1);

bool isPalindrome(string s){
    //cout << s << endl;
    int n = s.size()/2;
    for(int i = 0; i<n; i++){
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}


int main()
{
    #ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    #else
        fastIO;
    #endif
    string s;
    bool a, b, c;
    cin >> s;
    a = isPalindrome(s);
    b = isPalindrome(s.substr(0, (s.size()-1)/2));
    c = isPalindrome(s.substr(((s.size()+3)/2-1), s.size()));
    //cout << a << " " << b << " " << c << endl;
    if(a && b && c)
        cout << "Yes" << endl;
    else cout << "No" << endl;

        return 0;

}