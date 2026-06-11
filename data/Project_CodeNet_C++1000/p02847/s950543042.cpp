#include <bits/stdc++.h>
#define ll long long
#define vl vector<ll int>
#define vs vector<string>
#define v vector<int>
#define mi map<int,int>
#define mc map<char,int>
//ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	cin>>s;
	if(s=="SUN"){
		cout<<7 <<"\n";
		}	
		else if(s=="MON"){
			cout<<6 <<"\n";
			}
			else if(s=="TUE"){
				cout<<5 <<"\n";
				}
				else if(s=="WED"){
					cout<<4 <<"\n";
					}
					else if(s=="THU"){
						cout<<3 <<"\n";
						}
						else if(s=="FRI"){
							cout<<2 <<"\n";
							}
							else if(s=="SAT"){
								cout<<1 <<"\n";
								}
}
