#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;

int main(){
	int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> perm(n);
    for(int i = 0; i < n; i++){
        int inp;
        cin >> inp;
        p.at(i) = inp;
        perm.at(i) = i + 1;
    }
    for(int i = 0; i < n; i++){
        int inp;
        cin >> inp;
        q.at(i) = inp;
    }

    int count = 0;
    int check = 0;
    int np = -1;
    int nq = -1;
    do{
        if(np >= 0 && nq >= 0) break;
        for(int i = 0; i < n; i++){
            if(perm.at(i) != p.at(i)) break;
            else if(i == n - 1) np = count;
        }
        for(int i = 0; i < n; i++){
            if(perm.at(i) != q.at(i)) break;
            else if(i == n - 1) nq = count;
        }
        count++;
    }while(next_permutation(perm.begin(), perm.end()));

    cout << abs(np - nq) << endl;
  	return 0;
}
