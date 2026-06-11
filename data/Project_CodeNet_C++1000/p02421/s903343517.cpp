#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num;
    int win_point = 3;
    int draw_point = 1;
    int taro_point = 0;
    int hanako_point = 0;
    string card_taro, card_hanako;

    cin >> num;
    for (int i = 0; i < num; ++i)
    {
        cin >> card_taro >> card_hanako;
        if (card_taro > card_hanako){
            taro_point += win_point;
        }else if(card_taro < card_hanako){
            hanako_point += win_point;
        }
        else{
            taro_point += draw_point;
            hanako_point += draw_point;
        }
    }
    cout << taro_point << " " << hanako_point << endl;
}
