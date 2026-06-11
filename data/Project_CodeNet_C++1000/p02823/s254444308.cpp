#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;
int main()
{
	ll N,A,B,ANS;
	cin>>N>>A>>B;
	if(abs(A-B)%2==0){
		cout<<abs(A-B)/2<<endl;
	}
	else{
		ll G;
		vector<pair<ll,ll>>AA,BB;
		AA.push_back(make_pair(abs(1-A),1));
		AA.push_back(make_pair(abs(N-A),2));
		BB.push_back(make_pair(abs(1-B),3));
		BB.push_back(make_pair(abs(N-B),4));
		sort(AA.begin(),AA.end());
		sort(BB.begin(),BB.end());
		if(AA[0].first<=BB[0].first){
			if(AA[0].second==1){
				G=AA[0].first;
				A=1;
				B=B-G-1;
			}
			else{
				G=AA[0].first;
				A=N;
				B=B+G+1;
			}
			//cout<<G<<":"<<A<<":"<<B<<endl;
			cout<<G+abs(A-B)/2+1<<endl;
		}
		else{
			if(BB[0].second==3){
				G=BB[0].first;
				B=1;
				A=A-G-1;
			}
			else{
				G=BB[0].first;
				B=N;
				A=A+G+1;
			}
			//cout<<G<<":"<<A<<":"<<B<<endl;
			cout<<G+abs(A-B)/2+1<<endl;
		}

	}
}