#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int n, k;
    int r, s, p;
    string T;
    cin >> n >> k >> r >> s >> p >> T;

    int point = 0;
    for(int i = 0; i < k; i++){
        char before = T[i];
        int count = 1;
        for(int j = i + k; j < n; j += k){
            if (before != T[j]){
                int l;
                if (before == 'r')l = p;
                else if (before == 's')l = r;
                else if (before == 'p')l = s;
                point += (count + 1) / 2 * l;

                before = T[j];
                count = 1;
            }
            else{
                count++;
            }
        }
        int l;
        if (before == 'r')l = p;
        else if (before == 's')l = r;
        else if (before == 'p')l = s;
        point += (count + 1) / 2 * l;
    }
    cout << point << endl;
    return 0;
}