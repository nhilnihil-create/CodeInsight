#include <bits/stdc++.h>
 
using namespace std;
 
template<class e, class t, int N>
std::basic_istream<e,t>& operator>>(std::basic_istream<e,t>& in, const e(&literal)[N]) {
        std::array<e, N-1> buffer; //get buffer
        in >> buffer[0]; //skips whitespace
        if (N>2)
                in.read(&buffer[1], N-2); //read the rest
        if (strncmp(&buffer[0], literal, N-1)) //if it failed
                in.setstate(in.rdstate() | std::ios::badbit); //set the state
        return in;
}
template<class e, class t>
std::basic_istream<e,t>& operator>>(std::basic_istream<e,t>& in, const e& literal) {
        e buffer;  //get buffer
        in >> buffer; //read data
        if (buffer != literal) //if it failed
                in.setstate(in.rdstate() | std::ios::badbit); //set the state
        return in;
}
//redirect mutable char arrays to their normal function
template<class e, class t, int N>
std::basic_istream<e,t>& operator>>(std::basic_istream<e,t>& in, e(&carray)[N]) {
        return std::operator>>(in, carray);
}
 
template<class t>
istream & operator>>(istream& in,vector<t> &v) {
    for(int i = 0; i < v.size();i++)in>>v[i];
    return in;
}
template<class t1,class t2>
istream & operator>>(istream& in,pair<t1,t2> &v) {
    cin>>v.first>>v.second;
    return in;
}
template<class t> 
ostream & operator<<(ostream & out, vector<t> & a){
    for(auto x : a){
        out << x <<" ";
    }
    return out;
}
template<class t> 
ostream & operator<<(ostream & out, set<t> & a){
    for(auto x : a){
        out << x <<" ";
    }
    return out;
}
template<class t1, class t2> 
ostream & operator<<(ostream & out, map<t1,t2> & a){
    for(auto x : a){
        out << x.first << " = " << x.second << endl;
    }
    return out;
}
template<class t1,class t2>
ostream & operator<<(ostream & out,const pair<t1,t2> & a){
    out << a.first<<" "<<a.second;
    return out;
}
template<class t1,class t2>
pair<t1,t2> operator+(const pair<t2,t1>& a,const pair<t1,t2> & b){
    return {a.first + b.first, a.second + b.second};
}
template<class t1,class t2>
pair<t1,t2> operator-(const pair<t2,t1>& a,const pair<t1,t2> & b){
    return {a.first - b.first, a.second - b.second};
}
 
 
//#define PRAGMA 448
#ifdef PRAGMA
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
 
#ifdef LUCARIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl;
#define FIN 0
#else
#define deb(...) 0
#define deb1(x) 0
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
 
typedef pair<long long,long long> pll;
typedef pair<int,int> pii;
typedef pair<string,int> psi;
 
#define ll long long
#define ld long double
#define int long long
#define pb push_back
#define bs binary_search 
#define up upper_bound // >
#define lb lower_bound // >=
#define f first 
#define s second 
#define fst first 
#define snd second 
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define mp make_pair     
#define endl "\n" 
 
#define fore(i,a,b) for(ll i = a; i < (ll)b; i++)
#define rfore(i, a, b) for(ll i = b - 1; i >= (ll)a; i--)
#define bin(aaa,bbb) fore(_,0,bbb)cout<<((aaa & (1<<_)) != 0);cout<<endl;
#define mm(a,b) memset(a , b , sizeof a) 
#define trans(a,b) transform(a.begin(),a.end(),a.begin(),b) //::tolower ::toupper
#define bpop(n) __builtin_popcount(n)
#define np(a) next_permutation(a.begin(), a.end())
#define ALL(a) a.begin(),a.end() 
#define SZ(n) ((ll) (n).size())
#define sfind(s,t) (s.find(t) != string::npos)
 
#define infll (ll)(1e16+3)
#define infi  (ll)(1e9+4)
#define pi acos(-1) 
#define mod (ll)(1e9+7)
#define eps  1e-7
#define YES "YES"
#define NO "NO"
 
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b,a%b); } 
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll fpow(ll b, ll e, ll m = mod){int r=1;while(e){if(e&1)r=(r*b)%m;e/=2;b=(b*b)%m;}return r;}

vector<pll> a;
map<pair<int,pll>,int> dp;
int n;



int32_t main(int32_t argc, char const *argv[]){
 	FIN;
    cin>>n;a.resize(n);
    cin>>a;

    int res=0;
    fore(j,0,100000){
        random_shuffle(ALL(a));
        int x=0,y=0;
        for(auto z : a){
            if( (x+z.f)*(x+z.f)+ ((y+z.s)*(y+z.s)) > x*x+y*y  ){
                x+=z.f;
                y+=z.s;
            }
        }

        res=max(res,x*x+y*y);
    }


    cout<<fixed<<setprecision(20)<<sqrt(res)<<endl;



 	return 0;    
} 



/*
Para las DP:
 
sLos arreglos donde estén los valores en lo posible se declaran como INT
siempre hacer int &r = dp...    
int res y trabapiijas todo con res
luego haces return r = res
cuando se trabaja se hace solve(...)+a[x];
 
break;
Fórmulas:
 
priority_queue < int,vector<int>,greater<int> > q; calse contenedor y comparacion
continue
break
cero = r/k  - (l/k + (l%k!=0)) +1; cantidad de números divisibles por k en el intervalo [l, r]
en un arreglo sircularde largo n si das saltos de largo m para volver al inicion nesesitas
n/gcd(n,m)
cantidad de inmeros en un rango lower_bound(r) -lowerbound(l-1)
upper_bound primer elemento mayor estricto
lower_bound primer elemento mayor o igual
Al hacer BFS con distancia recordar simpre antes de visitar preguntar si ya llegue antes con
un peso menor 
setprecision(15)
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
getline(cin,s); donde s es un string
si luego se van a haces unuevos cins hacer cin.ignore
 
__builtin_popcount(3) cantidad de unos en la reprewsentacion binaria
__builtin_clz() cantidad de 0 a la izquierda del primer numero
 __builtin_ffs evuelve 1+ el indise del uno menos significativo
 
TCL
 
tuple 
    tuple<tipo> nombre
    get<pos>(nombre) //forma de acceder
 
vector
    vector<tipo> nombre(cantidad,contenido)
    vector<int> nombre = {...}
    nombre.resize(tam,contenido si se agregan) //cambia el tamaño a tam
    nombre.pop_back() elimina el ultimo elemento
    nombre.back() // ultimo elemnto
 
set
    erase(it/elem)
    insert(elem)
 
rectas en un set
 
recta = az+by+c = 0 
recta entre 2 puntos
a = y1-y0 y b = x0-x1 => c = x1*y0-y1*x0
 
if(a<0 || (a==0 && b<0)) {
    a=-a;
    b=-b;
    c=-c;
}
d = gcd(a,b)
a,b /= gcd(a,b);
c,d /= gcd(d,c)
 
luego
 
 
*/