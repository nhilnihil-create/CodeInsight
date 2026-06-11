#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef tree<ii,null_type,less<ii>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;
	if (s=="SAT") cout<<"1"<<endl;
	else if (s=="FRI") cout<<"2"<<endl;
	else if (s=="THU") cout<<"3"<<endl;
	else if (s=="WED") cout<<"4"<<endl;
	else if (s=="TUE") cout<<"5"<<endl;
	else if (s=="MON") cout<<"6"<<endl;
	else if (s=="SUN") cout<<"7"<<endl;
	else cout<<endl;
	return 0;
}
