#include<bits/stdc++.h>
using namespace std;

#define gcd(a,b)		__gcd(a,b)
#define lcm(a,b)		(a*b)/gcd(a,b)
#define ff              first
#define ss              second
#define int             long long
#define float			double
#define pb              emplace_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define vc				vector<char>
#define vb				vector<bool>
#define vf				vector<float>
#define vs				vector<string>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int>>
#define hashmap         unordered_map
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             INT64_MAX
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define all(x)			x.begin(),x.end()
#define digits(x)		floor(log10(x))+1
#define FIO				ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

template<class T>
void printV(vector<T> a) {for (auto v : a)cout << v << " ";}
template<class T>
void readV(vector<T>& a) {int n = a.size(); for (int i = 0 ; i < n ; i++)cin >> a[i];}
template<class T>
void printA(T* a , int n) {for (int i = 0; i < n  ; i++)cout << a[i] << " ";}
template<class T>
void readA(T* a , int n) {for (int i = 0 ; i < n ; i++)cin >> a[i];}
auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
void run_time() {cout << endl<<"Time elapsed: " << (double)(clock() - clk) / CLOCKS_PER_SEC << endl;}

void aryan_pandeya() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class dsu{
private:
    int* parent;
    int* size;

    int root(int x){
        while(x!=parent[x]){
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
public:
    int components;
    dsu(int n){
        parent = new int [n];
        size = new int [n];
        components = n ;
        for(int i = 0 ; i<n ; i++){
            parent[i] = i ;
            size[i] = 1;
        }
    }
    bool find(int x , int y){
        return root(x)==root(y);
    }
    void join(int x , int y){
        int i = root(x);
        int j = root(y);
        if(i==j){
            return ;
        }
        else{
            components--;
            if(size[i]<size[j]){
                parent[i] = j;
                size[j]+=size[i];
                size[i] = 0;
            }
            else{
                parent[j] = i ; 
                size[i]+=size[j];
                size[j] = 0;
            }
        }
    }
    int sz(int x){
        return size[x];
    }
};


int32_t main() {
	aryan_pandeya();
	FIO;
 
    int n,q;
    cin>>n>>q;

    dsu g(n);
    
    for(int i = 0 ; i<q ; i++){
        int t,x,y;
        cin>>t>>x>>y;

        if(t==1){
            cout<<g.find(x,y)<<'\n';
        }
        else{
            g.join(x,y);
        }
    }



	return 0;
}
