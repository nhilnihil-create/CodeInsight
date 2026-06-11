#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for( int i=a; i<b; i++ )
#define REP(i,n) rep(i,0,n)
#define INF 1000000000000
using lli = long long int;
using ulli = unsigned long long int;
typedef pair<lli,lli> P;

struct edge{ int u, v; lli cost; };
struct DirectedGraph
{
  int vertex_num;
  int edge_num;
  vector<edge> edge_list;
  vector< vector<int> > adj_list;
	vector< vector<lli> > distance_matrix;
};

template <typename T>
vector<int> argsort(const vector<T> &v) {

  // initialize original index locations
  vector<int> idx(v.size());
  iota(idx.begin(), idx.end(), 0);

  // sort indexes based on comparing values in v
  sort(idx.begin(), idx.end(),
       [&v](int i1, int i2) {return v[i1] < v[i2];});

  return idx;
}

template<typename T>
void displayVector(vector<T> v)
{
	lli n = v.size();
	REP(i,n){
		cout << v[i] << " " ;
	}
	cout << endl;
}



int main(){
	int N; cin >> N; 
	vector<lli> a(N), b(N,0), sum(N,0);
	REP(i,N){ cin >> a[i]; }

	for(int iter=N;0<iter;iter--){
		if(a[iter-1] != sum[iter-1]%2 ){ 
			for (lli i = 1; i * i <= iter; i++) {
        if (iter % i == 0) {
            sum[i-1]+=1;
            if (i * i != iter) sum[iter/i-1] += 1;
        }
			}
			b[iter-1] = 1;
    }
	}
	cout << accumulate(b.begin(), b.end(), 0) << endl;
	REP(i,N){
		if(b[i]){ cout << i+1 << endl; }
	}
	return 0;
}