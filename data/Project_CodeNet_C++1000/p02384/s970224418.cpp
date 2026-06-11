//チェッカーコンパイルエラー

#include<bits/stdc++.h>
using std::cout;
using std::cin;
using std::endl;


class dice
{
    private:
        int roll[6];

    public:
        explicit dice(int in[6]){
            for (int i = 0; i < 6; i++)
                roll[i] = in[i];
        }

        void move(const char c){
            int tmp;
            switch(c){
                case 'N':
                    tmp = roll[0];
                    roll[0] = roll[1];
                    roll[1] = roll[5];
                    roll[5] = roll[4];
                    roll[4] = tmp;
                    break;

                case 'E':
                    tmp = roll[0];
                    roll[0] = roll[3];
                    roll[3] = roll[5];
                    roll[5] = roll[2];
                    roll[2] = tmp;
                    break;

                case 'W':
                    tmp = roll[0];
                    roll[0] = roll[2];
                    roll[2] = roll[5];
                    roll[5] = roll[3];
                    roll[3] = tmp;
                    break;

                case 'S':
                    tmp = roll[0];
                    roll[0] = roll[4];
                    roll[4] = roll[5];
                    roll[5] = roll[1];
                    roll[1] = tmp;
                    break;

                default:
                    cout << "Wrong Direction: "
                         << c << endl;
                    break;
            }
        }
        int operator()(size_t i){
            return roll[i];
        }
};
/*
int Pr(dice d, int up, int front){
    char dir[] = {'N', 'E', 'W', 'S'};
    std::random_device seed_gen;
    std::default_random_engine engine(seed_gen);

    std::uniform_int_distribution<> dist(0, 3);

    while (d(1)!=front)
        d.move(dir[dist(engine)]);
    
    while (d(0)!=up)
        d.move('S');

    return d(2);
}*/

/*
int p_r(dice d,int up,int front){

    int n;

    //std::uniform_int_distribution<> dist(0, 3)
    //auto rgen = std::bind(std::uniform_int_distribution<>(0,3),std::mt19937(seed_gen()));
    char dir[]={'N','E','W','S'};
    while(front!=d(1))
    {
        //n = dist(engine);
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen());
        auto rgen = std::bind(std::uniform_int_distribution<>(0,3),std::mt19937(seed_gen()));
        cout << ":" << rgen() << endl;
        d.move(dir[rgen()]);
    }
    while (up!=d(0))
        d.move('S');
    
    return d(2);
}
*/

int p_r(dice d, int up, int front){
    int i = 0;
    while (i < 4)
    {
        if (d(1)==front)
            break;
        d.move('N');
        i++;
    }

    if(d(1)!=front)
    {
        d.move('W'); d.move('N');
        if(d(1)!=front)
        {    d.move('S'); d.move('S');}

    }

    i = 0;
    while (i < 4)
    {
        if(d(0)==up)
            break;
        d.move('W');
        i++;
    }


    return d(2);  
}

int main()
{
    int eye[6], n, up, front;;

    for (int i = 0; i < 6; i++)
    {    
        cin >> eye[i];
    }
    
    cin >> n;
    int result[n]={0};
    
    dice d(eye);

    for (int i = 0; i < n; i++)
    {
        cin >> up >> front;
        result[i] = p_r(d, up, front);
    }

    
    
    for (int i = 0; i < n; i++)
        cout << result[i] << endl;
    

    return 0;
}
