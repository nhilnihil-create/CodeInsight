#include<bits/stdc++.h>

int M;
struct Point{
    double x, y;
};

int rec(Point start, Point end, int i){
    if(i == M){
	return 0;
    }
    Point p1, p2, p3;
    p1.x = (2 * start.x + end.x) / 3;
    p1.y = (2 * start.y + end.y) / 3;
    p3.x = (start.x + 2 * end.x) / 3;
    p3.y = (start.y + 2 * end.y) / 3;

    p2.x = (p3.x - p1.x) * std::cos(M_PI / 3) - (p3.y - p1.y) * std::sin(M_PI / 3) + p1.x;
    p2.y = (p3.x - p1.x) * std::sin(M_PI / 3) + (p3.y - p1.y) * std::cos(M_PI / 3) + p1.y;

    rec(start, p1, i+1);
    std::cout << p1.x << " " << p1.y << std::endl;
    rec(p1, p2, i+1);
    std::cout << p2.x << " " << p2.y << std::endl;
    rec(p2, p3, i+1);
    std::cout << p3.x << " " << p3.y << std::endl;
    rec(p3, end, i+1);
    
    
}

int main(void){
    Point start, end;
    start.x = 0;
    start.y = 0;
    end.x = 100;
    end.y = 0;

    std::cin >> M;

    std::cout << start.x << " " << start.y << std::endl;
    rec(start, end, 0);
    std::cout << end.x << " " << end.y << std::endl;

    return 0;
}

