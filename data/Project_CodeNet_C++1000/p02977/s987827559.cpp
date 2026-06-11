#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;

int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if(n <= 2) {
        cout << "No" << endl;
        return 0;
    }
    int chain = 0;
    for(int pw = 2;; pw++) {
        if((1<<pw)-1 <= n) chain = (1<<pw)-1;
        else break;
    }
    int baki = n - chain;
    if(baki == 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<pair<int,int>> edge;
    if(baki%2 == 0) {
        for(int i = 1; i < chain; i++) {
            edge.push_back({i, i+1});
            edge.push_back({n+i, n+i+1});
        }
        edge.push_back({chain, n+1});
        int Xor = 0;
        for(int i = chain+1; i <= n; i++) {
            Xor ^= i;
        }
        if(baki) {
            for(int i = chain+1; i < n; i++) {
                edge.push_back({i, i+1});
                edge.push_back({n+i,n+i+1});
            }
            if(Xor) {
                edge.push_back({n, Xor});
                edge.push_back({Xor, n+chain+1});
            }
            else {
                edge.push_back({n, n+chain+1});
                edge.push_back({1, chain+1});
            }
        }
    }
    else {
        int Xor = 0;
        for(int i = chain+1; i < n; i++) {
            Xor ^= i;
        }
        if(Xor) {
            vector<int> line;
            for(int i = 1; i <= chain; i++) {
                line.push_back(i);
            }
            swap(line[0], line[Xor-1]);
            int z = n^(n-1);
            if(z != Xor) {
                for(int i = 0; i < line.size(); i++) {
                    if(line[i] == z) {
                        swap(line[i], line.back());
                        break;
                    }
                }
            }
            for(int i = 0; i + 1 < line.size(); i++) {
                int x = line[i], y = line[i+1];
                edge.push_back({x, y});
                edge.push_back({n + x, n + y});
            }
            edge.push_back({line.back(), n + line[0]});
            for(int i = chain+1; i+1 < n; i++) {
                edge.push_back({i, i+1});
                edge.push_back({n+i,n+i+1});
            }
            edge.push_back({n-1, line[0]});
            edge.push_back({line[0], n+chain+1});
            edge.push_back({n-1, n});
            if(z == Xor) edge.push_back({line[0], 2*n});
            else edge.push_back({line[line.size()-2]+n, 2*n});
        }
        else {
            vector<int> line;
            for(int i = 1; i <= chain; i++) {
                line.push_back(i);
            }
            int z = n^(n-1);
            swap(line[z-1], line[0]);
            for(int i = 0; i + 1 < line.size(); i++) {
                int x = line[i], y = line[i+1];
                edge.push_back({x, y});
                edge.push_back({n + x, n + y});
            }
            edge.push_back({line.back(), n + line[0]});
            for(int i = chain+1; i+1 < n; i++) {
                edge.push_back({i, i+1});
                edge.push_back({n+i,n+i+1});
            }
            edge.push_back({n-1, n+chain+1});
            edge.push_back({2*n-1, line[0]});
            edge.push_back({2*n-1,n});
            edge.push_back({line[0], 2*n});
        }
    }
    for(auto t : edge) {
        cout << t.first << " " << t.second << "\n";
    }
    return 0;
}

