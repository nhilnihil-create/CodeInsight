#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int x, y, z;
int boxes[3];
int main()
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x >> y >> z;

 
    boxes[0] = x;
    boxes[1] = y;
    boxes[2] = z;

    swap(boxes[0], boxes[1]);
    swap(boxes[0], boxes[2]);

    cout << boxes[0] << " " << boxes[1] << " " << boxes[2] << endl;

    
    return 0;
}
