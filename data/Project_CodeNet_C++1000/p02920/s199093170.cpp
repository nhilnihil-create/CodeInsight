#include<bits/stdc++.h>

using namespace std;
using ll = long long;

/*********************************/
template<class T> inline ostream& operator<<(ostream& os,vector<T> arr) {os << "["; for(int i = 0; i < (int)arr.size(); i++)os << arr[i] << (i == (int)arr.size() - 1 ? "]" : ",");os << endl;return os;}
template<typename A, typename B> ostream& operator<<(ostream& os, const pair<A,B>& p){os << "{" << p.first << "," << p.second << "}";return os; }
#define prvec(v) cerr<<#v<<": [";for(int __i = 0;__i < (int)(v).size(); __i++)cerr<<((v)[__i])<<(__i+1==(int)(v).size()?"]\n":",");
#define print(x) cerr<<#x<<": "<<(x)<<endl
/*********************************/

int main()
{
    int n; cin >> n;
    vector<int> ms(1<<n);
    for(int i = 0; i < (1<<n); i++)cin >> ms[i];
    sort(ms.begin(), ms.end());
    vector<int> a = {ms.back()}; //既に消してるやつ
    ms.pop_back();

    bool ok = true;


    for(int I = 0; I < n; I++) {
        vector<int> nxt;    //消される
        vector<int> remain;
        sort(ms.begin(), ms.end());
        sort(a.begin(), a.end(), greater<int>());

        for(auto i : a) {
            while(ms.size() && ms.back() == i) {
                remain.push_back(ms.back());
                ms.pop_back();
            }
            if(!ms.size()) {
                ok = false;
                break;
            }
            nxt.push_back(ms.back());
            ms.pop_back();
        }
        // print(nxt);
        // print(ms);
        if(!ok) {
            cout << "No" << endl;
            return 0;
        }
        for(auto i : nxt)a.push_back(i);
        for(auto i : remain)ms.push_back(i);
    }
    print(ms);
    cout << "Yes" << endl;

}