#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<iomanip>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{"; for(auto nth : list){ cout << nth << " ";}cout << "}" << endl;

using namespace std;

string table[]={"qwertasdfgzxcvb","yuiophjklnm"};


int main(){

		int n;
		vector<string> list;
		cin >> n;
		
		for(int i=0;i<n;i++){
			string str;
			cin >> str;
			list.push_back(str);	
		}

		cin >> n;
		
		bool flag=false,s_flag=false;

		for(int i=0;i<n;i++){
			string str;
			cin >> str;
			for(int k=0;k<list.size();k++){
				if(list[k]==str){
					if(flag==false){
						cout << "Opened by " << str << endl; 
						flag = true;
					}
					else if(flag==true){
						cout << "Closed by " << str << endl;
						flag = false;
					}
					s_flag=true;
				}
			}
			if(!s_flag){
				cout << "Unknown " << str << endl;
			}
			s_flag=false;
		}

}