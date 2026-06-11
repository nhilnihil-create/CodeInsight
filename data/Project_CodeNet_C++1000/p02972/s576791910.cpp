#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
 
using namespace std;

int main(){
    int N, tmp, cnt;  cin >> N;
    vector<int> v(N), b(N,0);
    queue<int> que;
    for(int i=0; i<N; i++)  cin >> v[i];
    for(int i=N-1; i>=0; i--){
        tmp = i;
        cnt = 0;
        while(tmp <= N-1){
            cnt += b[tmp];
            tmp += (i+1);
        }
        if(cnt%2 != v[i])  b[i] = 1;
    }
    cnt = 0;
    for(int i=0; i<N; i++){
        if(b[i] == 1){
            cnt++;
            que.push(i+1);
        }
    }
    cout << cnt << endl;
    tmp = que.size();
    for(int i=0; i<tmp; i++){
        cout << que.front() << " ";
        que.pop();
    }
}