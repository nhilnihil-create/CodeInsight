/*
* @Author: Kabid
* @Date:   {{create_time}}
* @Last Modified by:   Kabid
* @Last Modified time: 2020-09-19 13:28:41
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  in(x) scanf("%d",&x);
#define out(x) printf("%d",x);
#define  ins(x)  scanf("%s",x);
#define outs(x) printf("%s",x);
#define lin puts("");
#define _ putchar(' ');

int t;       //test cases
ll i, j;	 //iterators
ll n, k , p, q,  d, m, c, c1, c2, d1; //variables;
ll mx = LLONG_MIN, mn = LLONG_MAX;		// max min
string s, s1, s2;		// string
ll a [1000001], b [200001] , mox [200001];	// array
map <int, int > mp;
vector <vector<ll>> vc;
vector <ll> v;
set <ll> st;
bool r;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cin >> t; q = t;
	t = 1;
	while (t--) {


		/*cin >> s;
		n = s.size();
		for (i = n - 1; i > 0; i--) {
			for (j = i - 1; j >= 0; j--) {
				if (s[i] > s[j]) {
					swap(s[i], s[j]);
					cout << s << endl;
					break;
				}
			}
			if(j!=-1) break;
		}
		if (i == 0) {
			cout << "no answer" << endl;
		}*/
		cin >>n>> s;
		if(n%2){
			cout<<"No"<<endl;
		}
		else{
			for(i=0;i<n/2;i++){
				if(s[i]!=s[n/2+i]){
					cout<<"No"<<endl;
					break;
				}
			}
			if(i==n/2){
				cout<<"Yes"<<endl;
			}
		}
	}
	return 0;

}
