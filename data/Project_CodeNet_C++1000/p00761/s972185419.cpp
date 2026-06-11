#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int main(){
    while(1){
        int a, l;
        cin >> a >> l;
        if (a == 0) break;

        priority_queue<int> que;
        priority_queue<int, vector<int>, greater<int>> que2;

        vector<int> tmp;
        bool flag = false;

        int ans_j, ans_a, ans_i_j;

        for (int k = 1; k <= 20; k++){
            tmp.push_back(a);
            for (int i = 0; i < l; i++){
                que.push(a % 10);
                que2.push(a % 10);
                a /= 10;
            }
            int a_max = 0;
            int a_min = 0;
            for (int i = 0; i < l; i++){
                a_max *= 10;
                a_min *= 10;
                a_max += que.top();
                a_min += que2.top();
                que.pop(); que2.pop();
            }
            a = a_max - a_min;
            for (int i = 0; i < tmp.size(); i++){
                if (a == tmp[i]) {
                    flag = true;
                    ans_a = a;
                    ans_j = i;
                    ans_i_j = k - i;
                    break;
                }
            }
            if (flag) break;
        }
        cout << ans_j << " " << ans_a << " " << ans_i_j << endl;
    }
}
