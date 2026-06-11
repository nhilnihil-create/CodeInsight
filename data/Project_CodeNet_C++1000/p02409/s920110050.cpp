#include <iostream>

#define BUILDING_COUNT 4
#define FLOOR_COUNT 3
#define ROOM_COUNT 10

int main(void) {
  int residents[BUILDING_COUNT][FLOOR_COUNT][ROOM_COUNT] = {0};
  int n = 0;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int b = 0;
    int f = 0;
    int r = 0;
    int v = 0;

    std::cin >> b >> f >> r >> v;

    residents[b - 1][f - 1][r - 1] += v;
  }

  for (int i = 0; i < BUILDING_COUNT; i++) {
    for (int j = 0; j < FLOOR_COUNT; j++) {
      for (int k = 0; k < ROOM_COUNT; k++) {
	std::cout << " " << residents[i][j][k];
      }
      
      std::cout << std::endl;      
    }

    if (i < (BUILDING_COUNT - 1)) {
      std::cout << "####################" << std::endl;
    }
  }
  
  return 0;
}