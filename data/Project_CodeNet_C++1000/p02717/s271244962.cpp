    #include<iostream>
    using namespace std;
    int main(){
      int a, b, c, d;
      cin >> a >> b >> c;
      d = c;
      c = b;
      b = a;
      a = d;
      
      cout << a << " " << b << " " << c;
    }