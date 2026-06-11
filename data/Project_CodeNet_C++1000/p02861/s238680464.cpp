#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

struct Point{
public:
    int x,y;
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
};

double square(double x){return x*x;}
double distance(Point p1,Point p2){return sqrt( square(p1.x-p2.x) + square(p1.y-p2.y) );}

int factorial(int n){
    int f=1;
    for(int i=1;i<=n;i++){f*=i;}
    return f;
}
void solve(){
    int n;
    cin>>n;
    
    vector<Point> arr;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        arr.push_back(Point(x,y));
    }
    
    vi sequence(n); // gives the sequence of the indices 
    for(int i=0;i<n;i++){sequence[i]=i;}
    
    double sum=0.0;
    do{
        for(int i=0;i<n-1;i++){
            sum+=distance(arr[sequence[i]],arr[sequence[i+1]]);
        }
    }while(next_permutation(sequence.b(),sequence.e()));
    
    
    cout<<setprecision(12)<<sum/factorial(n);
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}