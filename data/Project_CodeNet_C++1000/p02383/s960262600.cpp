#include <array>
#include <iostream>
#include <sstream>

class Dice {
 private:
  std::array<int, 6> inner_;

 public:
  Dice(std::string str) {
    std::istringstream stream(str);
    for(int i = 0; i != 6; ++i) {
      stream >> inner_[i];
    }
  }

  void roll(char dir) {
    std::array<int, 6> new_dice;
    switch(dir) {
    case 'N':
      new_dice[0] = inner_[1];
      new_dice[1] = inner_[5];
      new_dice[2] = inner_[2];
      new_dice[3] = inner_[3];
      new_dice[4] = inner_[0];
      new_dice[5] = inner_[4];
      break;
    case 'S':
      new_dice[0] = inner_[4];
      new_dice[1] = inner_[0];
      new_dice[2] = inner_[2];
      new_dice[3] = inner_[3];
      new_dice[4] = inner_[5];
      new_dice[5] = inner_[1];
      break;
    case 'W':
      new_dice[0] = inner_[2];
      new_dice[1] = inner_[1];
      new_dice[2] = inner_[5];
      new_dice[3] = inner_[0];
      new_dice[4] = inner_[4];
      new_dice[5] = inner_[3];
      break;
    case 'E':
      new_dice[0] = inner_[3];
      new_dice[1] = inner_[1];
      new_dice[2] = inner_[0];
      new_dice[3] = inner_[5];
      new_dice[4] = inner_[4];
      new_dice[5] = inner_[2];
      break;
    }
    inner_ = new_dice;
  }

  int get(int i) {
    return inner_.at(i);
  }

  friend std::ostream &operator<<(std::ostream &out, const Dice &dice) {
    for(int i = 0; i != 5; ++i) {
      out << dice.inner_.at(i) << " ";
    }
    out << dice.inner_.at(5);
    return out;
  }
};

int main() {
  std::string line;
  std::getline(std::cin, line);
  Dice dice(line);
  std::string dirs;
  std::getline(std::cin, dirs);
  for(const auto &dir : dirs) {
    dice.roll(dir);
  }

  std::cout << dice.get(0) << std::endl;

  return 0;
}