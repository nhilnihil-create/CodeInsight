#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, (b)<(e)?1:-1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define lp(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define each(x, a) for (auto &x: a)
#define pb push_back
template<class A> void read(vector <A>& v);
template<class A, size_t S> void read(array <A, S>& a);
template<class T> void read(T& x) {
    cin >> x;
}
void read(double& d) {
    string t;
    read(t);
    d=stod(t);
}
void read(long double& d) {
    string t;
    read(t);
    d=stold(t);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}
template<class A> void read(vector<A>& x) {
    each(a, x)
        read(a);
}
template<class A, size_t S> void read(array<A, S>& x) {
    each(a, x)
        read(a);
}

const int di[8] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
const int dj[8] = {1 , -1 , 0 , 0 , 1 , -1 , 1 , -1};


void Suhaib_Sawalha (){

    int n , k;
    read(n,k);
    int d , a;
    int ex[n] = {};
    while (k--){
        read(d);
        while (d--){
            read(a);
            ex[a-1] = 1;
        }
    }

    cout << n - accumulate(ex,ex+n,0);

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
// int _;cin>>_;for(int i=1;i<=_;++i,cout<<'\n')
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}
