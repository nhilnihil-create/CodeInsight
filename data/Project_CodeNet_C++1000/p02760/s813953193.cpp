#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, pair<int, int>> pos;

    for(int i=0, val; i<3; i++) {
        for(int j=0; j<3; j++) {
            cin >> val;

            pos[val] = {i, j};
        }
    }

    bool card[3][3] = {{0, 0, 0},{0, 0, 0},{0, 0, 0}};

    int q;
    cin >> q;

    for(int i=0, val; i<q; i++)
    {
        cin >> val;

        if(pos.count(val))
        {
            int x = pos[val].first;
            int y = pos[val].second;

            card[x][y] = true;
        }
    }

    bool bingo = false;

    bingo |= (card[0][0] && card[0][1] && card[0][2]);
    bingo |= (card[1][0] && card[1][1] && card[1][2]);
    bingo |= (card[2][0] && card[2][1] && card[2][2]);

    bingo |= (card[0][0] && card[1][0] && card[2][0]);
    bingo |= (card[0][1] && card[1][1] && card[2][1]);
    bingo |= (card[0][2] && card[1][2] && card[2][2]);

    bingo |= (card[0][0] && card[1][1] && card[2][2]);
    bingo |= (card[0][2] && card[1][1] && card[2][0]);

    cout << (bingo ? "Yes" : "No") << '\n';

    return 0;
}
