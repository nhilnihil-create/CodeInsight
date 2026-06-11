#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N, M;
    vector<int> ans, check;

    cin >> N >> M;
    ans.resize(N, 0);
    check.resize(N, 0);
    if(N != 1){
        ans[0] = 1;
    }
    for (int i = 0; i < M; i++){
        int s, c;
        cin >> s >> c;
        s--;
        if((N != 1) && (s == 0) && (c == 0)){
            cout << -1 << endl;
            return 0;
        }
        if((check[s] != 0) && (ans[s] != c)){
            cout << -1 << endl;
            return 0;
        }
        check[s]++;
        ans[s] = c;
    }

    string str = "";
    for (int i = 0; i < ans.size(); i++){
        str += (char)(ans[i] + '0');
    }
    cout << atoi(str.c_str()) << endl;
}