#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a;
    vector<int> b;
    int tmp;
    for (int i = 0; i < A; i++)
    {
        cin >> tmp;
        a.emplace_back(tmp);
    }
    for (int i = 0; i < B; i++)
    {
        cin >> tmp;
        b.emplace_back(tmp);
    }
    
    int x, y, c;
    int pri;
    int min = 200000;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y >> c;
        pri = a[x - 1] + b[y - 1] - c;
        if (pri < min)
        {
            min = pri;
        }
        
    }
    pri = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
    if (pri < min)
    {
        min = pri;
    }
    
    cout << min << endl;

    return 0;
}