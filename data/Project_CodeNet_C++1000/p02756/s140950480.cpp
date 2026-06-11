#include <bits/stdc++.h>
using namespace std;

void Main()
{
    string s;
    int q;
    cin >> s >> q;
    int r = 0;
    string sa, sb;
    for (int i = 0; i < q; i++)
    {
        int t, f;
        char c;
        cin >> t;
        if(t == 1) r++;
        else{
            cin >> f >> c;
            if(f == 1 && r % 2 == 0 || f == 2 && r % 2 == 1) sa += c;
            else sb += c;
        }
    }
    if(r % 2 == 1){
        swap(sa, sb);
        reverse(s.begin(), s.end());
    }
    reverse(sa.begin(), sa.end());

    cout << sa << s << sb << endl;
    
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
