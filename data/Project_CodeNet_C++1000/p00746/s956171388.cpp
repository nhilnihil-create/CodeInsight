#include <iostream>
#include <vector>
#include <tuple>
#include <array>
#include <initializer_list>

using namespace std;

int main(void)
{
    int  mm[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int N;
    while(cin >> N, N){
        vector<array<int, 2>> vs;
        vs.emplace_back();
        vs[0][0] = 0; vs[0][1] = 0;
        while(--N){
            int n, d;
            cin >> n >> d;
            auto t = vs[n];
            auto& m = mm[d];

            t[0] += mm[d][0];
            t[1] += mm[d][1];

            vs.emplace_back(t);
        }

        int maxX = 0, minX = 0, maxY = 0, minY = 0;
        for(auto& t: vs){
            auto x = t[0];
            auto y = t[1];
            if(maxX < x) maxX = x;
            if(minX > x) minX = x;
            if(maxY < y) maxY = y;
            if(minY > y) minY = y;
        }

        cout << maxY - minY + 1 << ' ' << maxX - minX + 1 << endl;
    }

    return 0;
}