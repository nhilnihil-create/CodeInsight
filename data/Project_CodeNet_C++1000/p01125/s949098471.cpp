#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

bool ma[128][128]={0};
int n, m, d;
char c;

int main(){

	while(cin >> n, n){
		
		queue<char> com;
		int x=10, y=10;
		
		memset(ma, 0, sizeof(ma));
		
		int a, b;
		
		for(int i=0; i<n; ++i){
			cin >> a >> b;
			ma[b][a] = true;
		}
		
		cin >> m;
		
		for(int i=0; i<m; ++i){
			
			cin >> c >> d;
			
			for(int i=0; i<d; ++i){	
				com.push(c);
			}	
		}
		
		if(ma[y][x]){
			n--;
			ma[y][x]=false;
		}
		
		while(!com.empty()){
			
			c = com.front();
			com.pop();
			
			if(c=='N')
				y++;
			else if(c=='E')
				x++;
			else if(c=='W')
				x--;
			else if(c=='S')
				y--;
				
			if(ma[y][x]){
				n--;
				ma[y][x]=false;
			}
		}
		
		cout << (!n?"Yes":"No") << endl;

	}

	return 0;
}