#include <bits/stdc++.h>
#define ll long long
#define intm INT_MAX
#define llm LLONG_MAX

using namespace std;
int MOD = 998244353;

int fronty[200030];
int backy[200030];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int N,k,c;
	string s;
	cin >> N >> k >> c >> s;
	vector<int> v1;
	for(int i=0; i < s.length(); i++){
        if( s[i] == 'o' ) v1.push_back(i+1);
	}
	vector<int> vf; vector<int> vb;
	vf.push_back(v1[0]); vb.push_back(v1[v1.size()-1]);
	int idxfront = 0;
	for(int i=1; i <=v1.size()-1; i++){
        if( v1[i]-v1[idxfront] >= c+1 ){
            vf.push_back(v1[i]);
            idxfront = i;
        }
	}
	int idxback = v1.size()-1;
	for(int i=v1.size()-2; i >= 0; --i){
        if( v1[idxback]-v1[i] >= c+1 ){
            vb.push_back(v1[i]);
            idxback = i;
        }
	}
	reverse( vb.begin(), vb.end() );
	/*
	for(auto c: vf) cout << c << " ";
	cout << endl;
	for( auto c: vb) cout << c << " ";
	cout << endl;
	*/
	for(int i=1; i <= k; i++) fronty[i] = vf[i-1];
	int xx = vb.size()-1;
	for(int i=k; i >= 0; --i){
        backy[i] = vb[xx];
        --xx;
	}


    for(int i=1; i <= k; i++){
        if( backy[i] == fronty[i] ) cout << fronty[i] << endl;
    }
    //
    //for(int i=1; i <= k; i++) cout << fronty[i] << " " << backy[i] << endl;





}
