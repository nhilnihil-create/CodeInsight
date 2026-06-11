#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n,a,c=0;
    cin >> n;
    vector <int> values;
    if(1>n || n>100)
        return 0;
    for(int i=0;i<n;i++){
        cin >> a;
        if(1>a || a>100)
            return 0;
        values.push_back(a);
    }
    for(int i=0;i<n;i=i+2){
            if(values[i]%2==1)
                c++;
    }
    cout << c;

    return 0;
}
