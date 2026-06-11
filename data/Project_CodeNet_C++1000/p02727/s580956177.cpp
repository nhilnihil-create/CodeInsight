#include <bits/stdc++.h>
using namespace std;

int inputAppleInfo(int nApples, deque<int>& apples, int arrayLength){
    for (int i = 0; i < nApples; i++){
        int p;
        cin >> p;
        apples.push_back(p);
    }
    sort( apples.begin(), apples.end(), greater<int>());
    while (apples.size() > arrayLength){
        apples.pop_back();
    }   
    return 0;
}

int main(void)
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    deque<int> SelectedRedApple;
    deque<int> SelectedGreenApple;
    deque<int> TransparentApple;
    inputAppleInfo(a, SelectedRedApple, x);
    inputAppleInfo(b, SelectedGreenApple, y);
    inputAppleInfo(c, TransparentApple, c);

    bool isSwap = true;
    while (isSwap && TransparentApple.size() > 0){
        int redMin = SelectedRedApple.back();
        int greenMin = SelectedGreenApple.back();
        int trMax = TransparentApple.front();
        int tmp = trMax;
        if ( (redMin <= greenMin) && (redMin < trMax) ){
            SelectedRedApple.push_front(tmp);
            SelectedRedApple.pop_back();
            TransparentApple.pop_front();
        }
        else if ( (greenMin < redMin) && (greenMin < trMax) ){
            SelectedGreenApple.push_front(tmp);
            SelectedGreenApple.pop_back();
            TransparentApple.pop_front();
        }
        else{
            isSwap = false;
        }
    }
    
    long ans = 0;
    for (auto itr = SelectedRedApple.begin(); itr != SelectedRedApple.end() ; itr++){
        ans += (long) *itr;
    }
    for (auto itr = SelectedGreenApple.begin(); itr != SelectedGreenApple.end() ; itr++){
        ans += (long) *itr;
    }
    cout << ans << endl;

    return 0;
}
