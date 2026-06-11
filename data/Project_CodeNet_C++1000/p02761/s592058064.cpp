#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>
using namespace std;


int main(void){
    int N,M;
    cin >> N >> M;
    string data;
    data += '1';
    for(int i =0; i < N-1; i++){
        data += '0';
    }

    if(N == 1){
        data[0] = '0';
    }
    vector<int> insert(N,0);
    for(int i =0; i < M; i++){
        int s, c;
        cin >> s >> c;

        if(s == 1 && c == 0 && N != 1){
            cout << -1 << endl;
            return 0;
        }else if(insert[s-1] == 0 || data[s-1] == (char)('0' + c)){
            data[s-1] = (char)('0' + c);
            insert[s-1] = 1;
        }else{
            cout << -1 << endl;
            return 0;
        }
        //cout << data <<endl;

    }
    cout << data <<endl;
}