#include <stack>
#include <string>
#include <iostream>
#include <utility>
using namespace std;
int main(void){
    string c;
    cin >> c;
    int length = c.length();
    int depth[length+10];
    for(int i = 0;i < length + 10; i++)
        depth[i] = 0;
    
    stack<pair<int,int> > S;
    for(int i = 0;i<length;i++){
        if(c[i] == '\\'){
            S.push(make_pair(0,i));
        }
        
        else if(c[i] == '_'){
            S.push(make_pair(1,i));
        }
        else if(c[i] == '/'){
            while(!S.empty() && S.top().first != 0 ){
                S.pop();
            }
            if(!S.empty()){
				for(int j=S.top().second;j < i;j++){
					depth[j+1]++;
				}
				S.pop();
            }
        }
    }
    float amounts[length+10] = {};
    float sum = 0.0;
    int cnt = 0;
    int start = 0;
    for(int i = start;i < length+1;i++){
        if(depth[i] == 0 && amounts[cnt] >= 1.0){
			cnt++;
		}
		amounts[cnt] += (depth[i] + depth[i+1])*0.50;
		sum += (depth[i] + depth[i+1])*0.50;
		
    }
    
    cout << (int)sum << endl;
    cout << cnt;
    if(cnt>0)
        cout << ' ';
    else cout << endl;
    for(int i = 0;i < cnt-1;i++){
        cout << amounts[i] << ' ';
    }
    if(cnt > 0)
        cout << (int)amounts[cnt-1] << endl;
    return 0;
}