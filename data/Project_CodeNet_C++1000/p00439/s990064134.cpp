#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, k;
    while(cin >>n >>k){
        if(n == 0 && k == 0) break;
        vector<int> vec;
        int max = 0, now = 0;
        for(int i = 0; i < k; i++){
            int tmp;
            cin >>tmp;
            max += tmp;
            now += tmp;
            vec.push_back(tmp);
        }
        for(int i = k; i < n; i++){
            int tmp;
            cin >>tmp;
            vec.push_back(tmp);
            now += tmp;
            now -= vec[i - k];
            if(max < now) max = now;
        }
        cout <<max <<endl;
    }
    return 0;
}