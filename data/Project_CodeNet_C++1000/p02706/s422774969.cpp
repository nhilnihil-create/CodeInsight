#include <iostream>
using namespace std;
int main() {
        int sum , m;
        cin >> sum >> m;
        int cs = 0;
        for(int i = 0 ; i < m ; i++){
            int y;
            cin >> y;
            cs+= y;
        }
        cout << max(sum - cs , -1) << endl;
}
